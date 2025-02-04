# Semáforo com Temporizador Periódico no Raspberry Pi Pico

## 📌 Descrição
Este projeto implementa um **semáforo funcional** utilizando o **Raspberry Pi Pico**, baseado em um **temporizador periódico** para alternância das cores do LED. O sistema foi desenvolvido em **linguagem C**, simulado no **Wokwi**, e configurado para rodar no **VS Code** com todas as dependências e SDK instalados. Além disso, há suporte para execução em hardware real, utilizando a placa de desenvolvimento **BitDogLab**.

## 🎯 Funcionalidade
- O LED **vermelho** acende por **3 segundos**.
- Em seguida, o LED **Verde** acende por **3 segundos**.
- Depois, o LED **Azul** acende por **3 segundos**.
- O ciclo **se repete indefinidamente**.

## 🛠 Requisitos

**Microcontrolador**: Raspberry Pi Pico ou Raspberry Pi Pico W (opcional)
- **Placa de Desenvolvimento:** BitDogLab (opcional).
- **Conta Criada no Wokwi Simulator**: [Wokwi](https://wokwi.com/).
- **Editor de Código**: Visual Studio Code (VS Code).
- **SDK do Raspberry Pi Pico** configurado no sistema.
- Ferramentas de build: **CMake** e **Ninja**.

## 🖥 Configuração dos Pinos

| Componente | GPIO |
|------------|------|
| LED Vermelho | GPIO 13 |
| LED Amarelo | GPIO 11 |
| LED Verde | GPIO 12 |

---

## 🚀 Como Executar

### **1️⃣ Clonar o Repositório**
```bash
git clone https://github.com/Anamacario/semaforo.git
cd semaforo
```

### **2️⃣ Compilar e Carregar no Raspberry Pi Pico**
- Conecte a placa ao computador em modo **BOOTSEL**.
- Compile o código e copie o arquivo `.uf2` para a unidade do Pico ou pressione "Run" no terminal.

### **3️⃣ Testar no Wokwi integrado no Vs Code**
- Abra o arquivo `diagram.json`  e clique em "Run Simulation".
- Aperte o botão para inciar o sistema.

---

## ⚙ Implementação Técnica

- **Uso de Temporizador Periódico**: A alternância dos LEDs é controlada por um **callback de temporizador** que altera o estado a cada 3 segundos.
- **Saída Serial**: Exibe mensagens de depuração indicando o estado do semáforo.

---

## 🔍 Testes Realizados
✅ Teste da alternância dos LEDs no tempo correto.  
✅ Teste da saída serial para depuração.  
✅ Execução no **simulador Wokwi** , **Wokwi no Vs Code** e no **BitDogLab**.  

---

## Autoria
- Ana Carla Macário
