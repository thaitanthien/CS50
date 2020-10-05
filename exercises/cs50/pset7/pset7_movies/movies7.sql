SELECT movies.title, ratings.rating FROM movies, ratings
WHERE movies.year = 2010 AND movies.id = ratings.movie_id
ORDER BY ratings.rating DESC, movies.title;
