SELECT DISTINCT people.name FROM people, stars
WHERE NOT people.name = 'Kevin Bacon'
AND people.id = stars.person_id
AND stars.movie_id IN
    (SELECT stars.movie_id FROM stars, people       -- select all movies that KB starred in
    WHERE people.name = 'Kevin Bacon'
    AND people.birth = 1958
    AND stars.person_id = people.id);