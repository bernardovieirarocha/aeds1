import os
import re
import subprocess

BLACK = "\033[30m"
RED = "\033[31m"
GREEN = "\033[32m"
YELLOW = "\033[33m"  # orange on some systems
BLUE = "\033[34m"
MAGENTA = "\033[35m"
CYAN = "\033[36m"
LIGHT_GRAY = "\033[37m"
DARK_GRAY = "\033[90m"
BRIGHT_RED = "\033[91m"
BRIGHT_GREEN = "\033[92m"
BRIGHT_YELLOW = "\033[93m"
BRIGHT_BLUE = "\033[94m"
BRIGHT_MAGENTA = "\033[95m"
BRIGHT_CYAN = "\033[96m"
WHITE = "\033[97m"

RESET = "\033[0m"  # called to return to standard terminal text color


def get_ex_directory_paths():
    """
    Scans the current directory and creates a list of paths for directories named ex*.
    """
    current_dir = "./"  # Get current working directory
    ex_directories = []
    for item in os.listdir(current_dir):
        if item.startswith("ex") and os.path.isdir(os.path.join(current_dir, item)):
            # Check if item starts with "ex" and is a directory
            ex_directories.append(os.path.join(current_dir, item))
    return ex_directories


def get_all_files(directory_path):
    """
    Creates a list of all files within a specified directory path.
    """
    file_list = []
    for item in os.listdir(directory_path):
        item_path = os.path.join(directory_path, item)
        if os.path.isfile(item_path):
            # Check if it's a file and add the full path to the list
            file_list.append(item_path)
    return file_list


def compileC(c_code):
    call_string = "gcc " + c_code + " -o " + c_code.replace(".c", "")
    return_code = subprocess.call(call_string, shell=True)
    if return_code == 0:
        print(f"Compilation {GREEN}successful!{RESET}\n")
        return 1
    else:
        print(f"Compilation {RED}failed!{RESET}\n")
        return 0


def write_report(reportFile, message, entrada):
    reportFile.write(
        f"-> O arquivo de saida gerado pelo seu programa {entrada.split('/')[-1].replace('entrada','saida')} e o arquivo de saida correta { 'saidascorretas/' + entrada.split('/')[-1].replace('entrada','saida')} sao diferentes.\n"
    )
    report.write(message.communicate()[0].decode())


ex_paths = get_ex_directory_paths()
ex_paths = sorted(ex_paths)
success = []
report = open("diff.txt", "w")

for ex_path in ex_paths:
    nome_ex = ex_path.split("/")[-1]
    print(f"{YELLOW}Processing {nome_ex}{RESET}\n")
    files_in_exDIR = get_all_files(ex_path)
    c_code = None
    for file in files_in_exDIR:
        if re.findall(r"^ex\d+\.c$", file.split("/")[-1]):
            c_code = file
            break
    if c_code:
        print(f"{GREEN}C code found! {RESET} {c_code.split('/')[-1]}")
        if compileC(c_code):
            executable = c_code.replace(".c", "")
            print(f"{YELLOW}Checking Input files...{RESET}\n")
            if os.path.exists(ex_path + "/entradas"):
                entradas_txt = get_all_files(ex_path + "/entradas/")
                entradas_txt = sorted(entradas_txt)
                for entrada in entradas_txt:
                    minha_saidaPATH = (
                        ex_path
                        + "/"
                        + entrada.split("/")[-1].replace("entrada", "saida")
                    )
                    command = executable + " < " + entrada + " > " + minha_saidaPATH
                    print(f"Running {command}")
                    run_code = subprocess.call(command, shell=True)
                    numberCurrentTest = (
                        entrada.split("/")[-1]
                        .replace("entrada", "")
                        .replace(".txt", "")
                    )
                    if run_code == 0:
                        print(
                            f"{GREEN}Execution successful of test {numberCurrentTest}!{RESET}"
                        )
                    else:
                        print(
                            f"{RED}Execution failed of test {numberCurrentTest}!{RESET}"
                        )
                    if os.path.exists(ex_path + "/saidascorretas"):
                        print(f"{BLUE}Checking Output files..{RESET}")
                        saidas_txt = get_all_files(ex_path + "/saidascorretas/")
                        minhaSaidaAtual = entrada.split("/")[-1].replace(
                            "entrada", "saida"
                        )
                        saidaCorretaAtual = "saidascorretas/" + entrada.split("/")[
                            -1
                        ].replace("entrada", "saida")
                        if os.path.exists(
                            ex_path + "/" + "saidascorretas/" + minhaSaidaAtual
                        ):
                            check_output = subprocess.Popen(
                                "diff -wB "
                                + ex_path
                                + "/"
                                + minhaSaidaAtual
                                + " "
                                + ex_path
                                + "/"
                                + saidaCorretaAtual,
                                shell=True,
                                stdout=subprocess.PIPE,
                            )
                            check_output.wait()
                            if not check_output.returncode:
                                print(
                                    f"{GREEN} PASSED!{RESET} {minhaSaidaAtual} and {saidaCorretaAtual} are the same!\n"
                                )
                                success.append(1)
                            else:
                                success.append(0)
                                write_report(report, check_output, entrada)
                                print(
                                    f"{RED}FAILED!{RESET} {minhaSaidaAtual} and {saidaCorretaAtual} are NOT the same!\n"
                                )
                        else:
                            print(f"{RED}Output files not found!\n{RESET}")
                    else:
                        print(f"{RED}Output directory not found!\n{RESET}")
            else:
                print(f"{RED}Input files found!{RESET}")
    else:
        print(f"{RED}No C code found!{RESET} ")


print(
    f"\nTotal of {YELLOW}{len(success)} tests{RESET} ran with {GREEN}{sum(success)} passed {RESET}and {RED}{len(success) - sum(success)} failed.{RESET}"
)
