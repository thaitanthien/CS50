SELECT people.name FROM people, movies, stars
WHERE people.id = stars.person_id
AND stars.movie_id = movies.id
AND movies.title = 'Toy Story';