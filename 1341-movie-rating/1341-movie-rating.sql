

(select u.name as results from users as u inner join movierating as mr on u.user_id =mr.user_id group by mr.user_id order by count(movie_id) desc , u.name  limit 1)
union all
(select m.title as results from  movies as m inner join movierating as mr on m.movie_id=mr.movie_id and mr.created_at like '2020-02%'
group by mr.movie_id order by avg(rating) desc , m.title limit 1

)

