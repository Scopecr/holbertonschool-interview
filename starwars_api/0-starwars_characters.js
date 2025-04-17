#!/usr/bin/node

const request = require('request');

// Base URL for the Star Wars API
const baseUrl = 'https://swapi-api.hbtn.io/api/people/5/';

// Function to get character name from a URL
function getCharacterName(characterUrl) {
  // Add format=json parameter if not already present
  const url = characterUrl.includes('?') ?
    `${characterUrl}&format=json` :
    `${characterUrl}?format=json`;

  return new Promise((resolve, reject) => {
    request(url, (error, response, body) => {
      if (error) {
        reject(`Error retrieving character: ${error}`);
        return;
      }

      if (response.statusCode !== 200) {
        reject(`Error: Received status code ${response.statusCode} for ${url}`);
        return;
      }

      try {
        const characterData = JSON.parse(body);
        resolve(characterData.name);
      } catch (parseError) {
        reject(`Error parsing character data: ${parseError}`);
      }
    });
  });
}

// Function to get and print all characters from a movie
function getMovieCharacters(movieId) {
  const filmUrl = `${baseUrl}/films/${movieId}/?format=json`;

  request(filmUrl, (error, response, body) => {
    if (error) {
      console.error(`Error: ${error}`);
      process.exit(1);
    }

    if (response.statusCode !== 200) {
      console.error(`Error: Could not retrieve movie with ID ${movieId}`);
      console.error(`Status code: ${response.statusCode}`);
      process.exit(1);
    }

    try {
      const filmData = JSON.parse(body);
      const charactersUrls = filmData.characters;

      // Process characters sequentially to maintain order
      const processCharacters = async () => {
        for (const url of charactersUrls) {
          try {
            const name = await getCharacterName(url);
            console.log(name);
          } catch (err) {
            console.error(`Error fetching character: ${err}`);
          }
        }
      };

      processCharacters();

    } catch (parseError) {
      console.error(`Error parsing film data: ${parseError}`);
      process.exit(1);
    }
  });
}

// Main function
function main() {
  // Get movie ID from command line arguments
  const args = process.argv.slice(2);

  if (args.length === 0) {
    console.log("Usage: node script.js <movie_id>");
    console.log("Example: node script.js 3");
    process.exit(1);
  }

  const movieId = parseInt(args[0], 10);

  if (isNaN(movieId)) {
    console.error("Error: Movie ID must be a number");
    process.exit(1);
  }

  getMovieCharacters(movieId);
}

// Run the script
main();
