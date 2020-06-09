
-- SQL 1
select title from movies where year = 2008;

-- SQL 2
select birth from people where name = "Emma Stone";

-- SQL3
select title from movies where year >= 2018 order by title;

-- SQL4
select count(movie_id) from ratings where rating >= 10.0;

-- SQL5
select title, year from movies where title like 'Harry Potter%' order by year;

-- SQL6
select avg(rating) from (select * from ratings join movies on ratings.movie_id = movies.id where year = 2012);

-- SQL7
select title, rating from (select * from ratings join movies on ratings.movie_id = movies.id where year = 2010) order by rating desc, title;

-- SQL8
select name
from people as p
join stars as s on p.id = s.person_id
join movies as m on s.movie_id = m.id
where title = "Toy Story";

-- SQL9
SELECT name
from people as p
where id in (
select distinct person_id
from stars as s join movies as m on s.movie_id = m.id
WHERE year = 2004);

-- SQL10
SELECT name
from people as p
where id in (
select distinct person_id
from directors as d
join movies as m on d.movie_id = m.id
join ratings as r on m.id = r.movie_id
WHERE rating >= 9);

-- SQL11
select title from (
select * from stars as s
join movies as m on s.movie_id = m.id
join people as p on s.person_id = p.id
join ratings as r on m.id = r.movie_id
where name = "Chadwick Boseman"
order by rating desc) limit 5;

-- SQL12
select title from (
select * from stars as s
join movies as m on s.movie_id = m.id
join people as p on s.person_id = p.id
where name = "Johnny Depp" or name = "Helena Bonham Carter"
group by title
having count(title) = 2);

-- SQL13
select name from people
where id in
(
  select distinct person_id from stars
  where movie_id in
  (
    select movie_id from stars as s
    join movies as m on s.movie_id = m.id
    join people as p on s.person_id = p.id
    where name = "Kevin Bacon" and birth = 1958
  )
)
and not name = "Kevin Bacon";
