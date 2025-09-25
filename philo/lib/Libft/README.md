<div align="center">

  <!-- Project badge -->
  <a href=".">
    <img src="assets/README/libftm.png">
  </a>

  <!-- Project name -->
  <h1>Libft</h1>

  <!-- Short description -->
  <p>A general purpose library in C.</p>

  <!-- Info badges -->
  <img src="https://img.shields.io/badge/Score-125%2F100-brightgreen?style=for-the-badge&labelColor=black" alt="Score">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&labelColor=black" alt="Language">
  <br>
  <img src="https://img.shields.io/github/last-commit/sdevsantiago/Libft?display_timestamp=committer&style=for-the-badge&labelColor=black" alt="Last commit">
  <br>
  <img src="https://github.com/sdevsantiago/Libft/actions/workflows/norminette.yml/badge.svg">
  <img src="https://github.com/sdevsantiago/Libft/actions/workflows/makefile.yml/badge.svg">
  </a>

</div>

---

## ℹ️ About Project

> The purpose of this project is to code a general purpose library in C that contains useful functions that further projects will rely upon.

This library reimplements many standard C library functions and adds additional utilities. It includes 100+ functions organized in several categories:

- **Part 1**: Standard C library functions (`ft_strlen`, `ft_strcpy`, `ft_atoi`, etc.)
- **Part 2**: Additional utility functions (`ft_split`, `ft_strjoin`, `ft_itoa`, etc.)
- **Bonus**: Linked list manipulation functions
- **Extra**: Custom extensions (multiple bases, advanced I/O, memory utilities)

For a complete list of functions, check the [`libft.h`](libft.h) header file.

For detailed info, refer to this project [subject](docs/en.subject.pdf).

## 🚀 Getting Started

### Prerequisites

- GCC compiler
- Make utility
- Unix-like system (Linux, macOS, WSL)

### Install prerequisites

- Debian/Ubuntu

  ```bash
  sudo apt install build-essential
  ```

## 🔧 Build

1. **Clone the repository:**
    ```bash
    git clone https://github.com/sdevsantiago/Libft.git
    cd Libft
    ```

2. **Compile the library:**
    ```bash
    make         # Full compilation (all functions)
    make bonus   # Include bonus functions (linked lists)
    make DEBUG=1 # Compile with debug flags
    ```

3. **Clean build files:**
    ```bash
    make clean  # Remove object files
    make fclean # Remove all generated files
    make re     # Rebuild everything from scratch
    ```

#### Available Make Targets

| Command | Description |
|---------|-------------|
| `make` | Compile all functions |
| `make all` | Same as `make` |
| `make bonus` | Compile with bonus functions (linked lists) |
| `make clean` | Remove object files (*.o) |
| `make fclean` | Remove object files and library |
| `make re` | Clean and rebuild everything |
| `make ... DEBUG=1` | Compile with debug flags (-g3) |

## 👨‍💻 Usage

### Basic Usage

1. **Include the header in your C file:**
   ```c
   #include "libft.h"
   ```

2. **Compile your program with the library:**
   ```bash
   cc -Wall -Wextra -Werror your_file.c path/to/libft/libft.a -I path/to/libft/ -o your_program
   ```

### Example Usage

**Simple string manipulation:**
```c
#include "libft.h"
#include <stdio.h>

// Helper function for ft_strmapi
char to_upper_wrapper(unsigned int _i, char c)
{
    (void)_i; // Suppress unused parameter warning
    return (ft_toupper(c));
}

int main(void)
{
    char *str = "Hello, 42!";
    char *upper_str;
    char **words;
    int i;

    // Convert to uppercase
    upper_str = ft_strmapi(str, to_upper_wrapper);
    printf("Original: %s\n", str);
    printf("Uppercase: %s\n", upper_str);

    // Split string
    words = ft_split("apple,banana,cherry", ',');
    printf("Fruits:\n");
    i = 0;
    while (words[i])
    {
        printf("- %s\n", words[i]);
        i++;
    }

    // Clean up memory
    free(upper_str);
    ft_free_split(words);
    return (0);
}
```

**Using linked lists (bonus functions):**
```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    t_list *list = NULL;
    t_list *current;

    // Add elements to the list
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("First")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Second")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Third")));

    // Print list contents
    current = list;
    while (current)
    {
        printf("- %s\n", (char *)current->content);
        current = current->next;
    }

    // Clean up
    ft_lstclear(&list, free);
    return (0);
}
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
