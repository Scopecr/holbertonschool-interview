#!/usr/bin/node

const request = require('request');

// Get the movie ID from command line arguments
const movieId = process.argv[2];

// URL for the film
const baseUrl = 'https://swapi-api.hbtn.io/api';
const filmUrl = `${baseUrl}/films/${movieId}/`;

request(filmUrl, (error, response, body) => {
  if (error || response.statusCode !== 200) {
    console.error('Error fetching movie data');
    return;
  }

  const filmData = JSON.parse(body);
  const characters = filmData.characters;

  // Process characters serially to maintain order
  const fetchCharacterData = (index) => {
    if (index >= characters.length) return;

    request(characters[index], (charError, charResponse, charBody) => {
      if (!charError && charResponse.statusCode === 200) {
        const character = JSON.parse(charBody);
        console.log(character.name);
      }

      fetchCharacterData(index + 1);
    });
  };

  // Start fetching characters
  fetchCharacterData(0);
});
