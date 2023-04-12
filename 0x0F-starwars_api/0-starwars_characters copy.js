#!/usr/bin/node

/*
JavaScript script that prints all characters of a Star Wars movie
API service: https://intranet.hbtn.io/rltoken/aiMsg1QkH-FuPn7gyo9O6A
use the request module
*/

const request = require('request');
const movieId = process.argv[2];

// Request URL
let url = 'https://swapi-api.hbtn.io/api/films/' + movieId;

request(url, async (error, response, body) => {
    // Printing the error if occurred
    if (error) console.log(error)

    // Printing body
    const characters = JSON.parse(body).characters;

    for (character in characters) {
        const urlChar = await characters[character];

        request(urlChar, async (error, response, body) => {
            // Printing the error if occurred
            if (error) console.log(error)

            const name = await JSON.parse(body).name;
            console.log(name);
        });
    }
});