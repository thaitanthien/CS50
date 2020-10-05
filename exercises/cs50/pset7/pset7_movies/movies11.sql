SELECT movies.title FROM movies, ratings, stars, people
WHERE movies.id = stars.movie_id
AND stars.person_id = people.id
AND people.name = 'Chadwick Boseman'
AND movies.id = ratings.movie_id
ORDER BY ratings.rating DESC LIMIT 5;