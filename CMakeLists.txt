# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
# Generated CMake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# == Configuração do Pico SDK ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()

set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()

# Definir a placa correta (Pico padrão)
set(PICO_BOARD pico CACHE STRING "Board type")

# Importar o SDK
include(pico_sdk_import.cmake)

# Nome do projeto
project(semaforo C CXX ASM)

# Inicializa o SDK do Pico
pico_sdk_init()

# Criar executável com o código correto
add_executable(semaforo semaforo.c)

pico_set_program_name(semaforo "semaforo")
pico_set_program_version(semaforo "0.1")

# Ativar comunicação UART/USB
pico_enable_stdio_uart(semaforo 1)
pico_enable_stdio_usb(semaforo 1)

# Vincular bibliotecas necessárias
target_link_libraries(semaforo
        pico_stdlib
        hardware_gpio
        hardware_timer
)

# Incluir diretórios do projeto
target_include_directories(semaforo PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

# Gerar arquivos extras (UF2, binário)
pico_add_extra_outputs(semaforo)
