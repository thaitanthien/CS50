SELECT movies.title FROM movies WHERE movies.id IN
    (SELECT stars.movie_id FROM stars, people WHERE stars.person_id = people.id AND people.name = 'Johnny Depp'
    INTERSECT
    SELECT stars.movie_id FROM stars, people WHERE stars.person_id = people.id AND people.name = 'Helena Bonham Carter';