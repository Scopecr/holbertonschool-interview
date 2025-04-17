# Star Wars Characters API

This project contains a script, `0-starwars_characters.js`, that interacts with the [Star Wars API (SWAPI)](https://swapi.dev/) to retrieve and display information about Star Wars characters.

## Description

The script fetches and prints the names of all characters from a specific Star Wars movie. The movie is identified by its episode number, which is passed as a command-line argument.

## Usage

1. Clone this repository to your local machine.
2. Ensure you have [Node.js](https://nodejs.org/) installed.
3. Run the script with the following command:

    ```bash
    node 0-starwars_characters.js <movie_id>
    ```

    Replace `<movie_id>` with the episode number of the desired Star Wars movie (e.g., `1` for "The Phantom Menace").

## Example

To fetch characters from Episode 1:

```bash
node 0-starwars_characters.js 1
```

This will output the names of all characters appearing in Episode 1.

## Dependencies

- The script uses the `request` library to make HTTP requests. Install it using:

  ```bash
  npm install request
  ```

## Author

This project is part of the Holberton School curriculum.