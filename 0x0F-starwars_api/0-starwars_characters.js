#!/usr/bin/node

const request = require('request');

const url = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}`;

request.get(url, async (error, response, body) => {
  if (error) console.log(error.message);
  const film = JSON.parse(body);

  for (const character of film.characters) {
    await new Promise((resolve) => {
      request.get(character, (error, response, body) => {
        if (error) console.log(error.message);
        const character = JSON.parse(body);
        console.log(character.name);
        resolve();
      });
    });
  }
});
