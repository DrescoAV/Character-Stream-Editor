# Character Stream Editor

## Author: Andrei-Valerian Andreescu

## Table of Contents

- [Magic Band Simulator](#magic-band-simulator)
  - [Author: Andrei-Valerian Andreescu](#author-andrei-valerian-andreescu)
  - [Table of Contents](#table-of-contents)
  - [Description](#description)
  - [Demo](#demo)
  - [How to run](#how-to-run)
  - [How to run the checker](#how-to-run-the-checker)
  - [Usage](#usage)
  - [Contributing](#contributing)
  - [License](#license)

## Description

The **Character Stream Editor** is a simple project that emulates a list of characters that can support operations. It allows you to perform operations on a list-like structure, which represents the stream. These operations include moving the cursor left or right, inserting characters, writing characters, undoing, redoing, and displaying the stream's content.
![Representation](https://github.com/DrescoAV/Character-Stream-Editor/blob/main/Demo/Character%20Stream%20Editor%20Representation.png)

## Demo

![Character Stream Editor Demo](https://github.com/DrescoAV/Character-Stream-Editor/blob/main/Demo/Character%20Stream%20Editor%20Demo.gif)

## How to run

To run the Character Stream Editor on your system, follow these steps:

1. Clone this repository to your local machine.
2. Compile the program by typing "make" into your terminal.
3. Create input and output files (e.g., `StreamEditor.in` and `StreamEditor.out`).
4. Run the compiled executable (e.g., `./StreamEditor StreamEditor.in StreamEditor.out`).

Make sure you have a C compiler installed on your system and that you are using a Linux distribution before proceeding.

## How to run the checker

```bash
./checker.sh
```

## Usage

Here are some examples of how to use the Character Stream Editor:

- Move the cursor right: `MOVE_RIGHT`
- Move the cursor left: `MOVE_LEFT`
- Move left until a specific character is found: `MOVE_LEFT_CHAR X`
- Move right until a specific character is found: `MOVE_RIGHT_CHAR Y`
- Write a character at the cursor position: `WRITE Z`
- Insert a character to the right of the cursor: `INSERT_RIGHT W`
- Insert a character to the left of the cursor: `INSERT_LEFT V`
- Undo the last operation: `UNDO`
- Redo the last undone operation: `REDO`
- Display the current state of the magic band: `SHOW`
- Display the character at the cursor position: `SHOW_CURRENT`

Please note that you need to replace `X`, `Y`, `Z`, `W`, and `V` with the specific characters you want to use.

## Contributing

Contributions to the Magic Band project are welcome! If you'd like to contribute, please follow these guidelines:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and ensure they pass any existing tests.
4. Create a pull request with a clear description of your changes.

We appreciate your contributions to make this project better.

## License

This project is licensed under the MIT License. See the [LICENSE](https://github.com/DrescoAV/Character-Stream-Editor/blob/main/LICENSE) file for details.
