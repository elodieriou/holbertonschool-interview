#!/usr/bin/node

const request = require('request');

const url = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}`;

request.get(url, async (response, body) => {
  const film = JSON.parse(body);

  for (const character of film.characters) {
    await new Promise((resolve) => {
      request.get(character, (response, body) => {
        const character = JSON.parse(body);
        console.log(character.name);
        resolve();
      });
    });
  }
});
