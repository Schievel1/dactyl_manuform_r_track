"""Format C code according to QMK's style.
"""
import subprocess
from shutil import which

from milc import cli
import qmk.path


def cformat_run(files, all_files):
    """Spawn clang-format subprocess with proper arguments
    """
    # Determine which version of clang-format to use
    clang_format = ['clang-format', '-i']
    for clang_version in [10, 9, 8, 7]:
        binary = 'clang-format-%d' % clang_version
        if which(binary):
            clang_format[0] = binary
            break
    try:
        if not files:
            cli.log.warn('No changes detected. Use "qmk cformat -a" to format all files')
            return False
        if files and all_files:
            cli.log.warning('Filenames passed with -a, only formatting: %s', ','.join(cli.args.files))
        # 3.6+: Can remove the str casting, python will cast implicitly
        subprocess.run(clang_format + [str(file) for file in files], check=True)
        cli.log.info('Successfully formatted the C code.')

    except subprocess.CalledProcessError:
        cli.log.error('Error formatting C code!')
        return False


@cli.argument('-a', '--all-files', arg_only=True, action='store_true', help='Format all core files.')
@cli.argument('-b', '--base-branch', default='origin/master', help='Branch to compare to diffs to.')
@cli.argument('files', nargs='*', arg_only=True, help='Filename(s) to format.')
@cli.subcommand("Format C code according to QMK's style.")
def cformat(cli):
    """Format C code according to QMK's style.
    """
    # Empty array for files
    files = []
    # Core directories for formatting
    core_dirs = ['drivers', 'quantum', 'tests', 'tmk_core']
    ignores = ['tmk_core/protocol/usb_hid', 'quantum/template']
    # Find the list of files to format
    if cli.args.files:
        files.extend(qmk.path.normpath(file) for file in cli.args.files)
    # If -a is specified
    elif cli.args.all_files:
        all_files = qmk.path.c_source_files(core_dirs)
        # The following statement checks each file to see if the file path is in the ignored directories.
        files.extend(file for file in all_files if not any(i in str(file) for i in ignores))
    # No files specified & no -a flag
    else:
        base_args = ['git', 'diff', '--name-only', cli.args.base_branch]
        out = subprocess.run(base_args + core_dirs, check=True, stdout=subprocess.PIPE)
        changed_files = filter(None, out.stdout.decode('UTF-8').split('\n'))
        filtered_files = [qmk.path.normpath(file) for file in changed_files if not any(i in file for i in ignores)]
        files.extend(file for file in filtered_files if file.exists() and file.suffix in ['.c', '.h', '.cpp'])

    # Run clang-format on the files we've found
    cformat_run(files, cli.args.all_files)
