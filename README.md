<div align="center">

  <!-- Project badge -->
  <a href=".">
    <img src="assets/README/philosopherse.png">
  </a>

  <!-- Project name -->
  <h1>Philosophers</h1>

  <!-- Short description -->
  <p>The classic Dining Philosophers problem in C.</p>

  <!-- Info badges -->
  <img src="https://img.shields.io/badge/Score-100%2F100-brightgreen?style=for-the-badge&labelColor=black" alt="Score">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&labelColor=black" alt="Language">
  <br>
  <img src="https://img.shields.io/github/last-commit/sdevsantiago/Philosophers?display_timestamp=committer&style=for-the-badge&labelColor=black" alt="Last commit">
  <br>
  <img src="https://github.com/sdevsantiago/Philosophers/actions/workflows/norminette.yml/badge.svg">
  <img src="https://github.com/sdevsantiago/Philosophers/actions/workflows/makefile.yml/badge.svg">

</div>

---

## ℹ️ About Project

> The purpose of this project is to learn the basics of threading and mutexes, while replicating the well-known Dining Philosophers problem.

For detailed info, refer to this project [subject](docs/en.subject.pdf).

## 🚀 Getting Started

### Prerequisites

- GCC compiler
- Make utility
- Unix-like system (Linux, macOS, WSL)

### Install prerequisites

- APT

  ```bash
  sudo apt install build-essential
  ```

- Pacman

  ```bash
  sudo pacman -Sy base-devel
  ```

## 🔧 Build

1. **Clone the repository:**
    ```bash
    git clone https://github.com/sdevsantiago/Philosophers.git
    cd Philosophers
    ```

2. **Compile the project:**
    ```bash
    make -C philo   # Compile mandatory only
    ```

3. **Clean build files:**
    ```bash
    make -C philo clean  # Remove object files
    make -C philo fclean # Remove all generated files
    make -C philo re     # Rebuild everything from scratch
    ```

## 👨‍💻 Usage

### Basic Usage

```bash
./philo 10 410 200 200
```

## 📏 Norminette

The code strictly complies with 42's **Norminette v4**:

```bash
norminette *.c *.h
```

More info in the official [Norminette](https://github.com/42school/norminette) repository.

## 🙇‍♂️ Special thanks

- [lrcouto](https://github.com/lrcouto) and [ayogun](https://github.com/ayogun) for creating and publishing, respectively, the [42-project-badges](https://github.com/ayogun/42-project-badges) repository.
- [gcamerli](https://github.com/gcamerli) for creating the [42unlicense](https://github.com/gcamerli/42unlicense) repository.

## ⚖️ License

<div align="center">

  <a href="./LICENSE">
    <img src="https://img.shields.io/badge/License-42_Unlicense-red?style=for-the-badge&labelColor=black">
  </a>

</div>

**This work is published under the terms of [42 Unlicense](LICENSE).** This means you are free to use, modify, and share this software.
