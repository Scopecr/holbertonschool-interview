#!/usr/bin/env node

const request = require('request');

// Get the movie ID from command line arguments
const movieId = process.argv[2];

if (!movieId) {
  console.error('Please provide a movie ID');
  process.exit(1);
}

// URL for the film
const filmUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/?format=json`;

// Get the film data
request(filmUrl, (error, response, body) => {
  if (error) {
    console.error(error);
    return;
  }

  if (response.statusCode !== 200) {
    console.error(`Error: Status code ${response.statusCode}`);
    return;
  }

  const film = JSON.parse(body);
  const characters = film.characters;

  // Process characters in order
  let characterIndex = 0;

  // Function to process next character
  const getNextCharacter = () => {
    if (characterIndex < characters.length) {
      const characterUrl = characters[characterIndex];
      characterIndex++;

      request(characterUrl, (charError, charResponse, charBody) => {
        if (!charError && charResponse.statusCode === 200) {
          const character = JSON.parse(charBody);
          console.log(character.name);
        }
        // Process next character regardless of errors to maintain ordering
        getNextCharacter();
      });
    }
  };

  // Start processing characters
  getNextCharacter();
});
