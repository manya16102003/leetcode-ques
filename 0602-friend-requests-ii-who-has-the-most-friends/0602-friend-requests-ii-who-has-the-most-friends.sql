with base as(select requester_id id from requestaccepted 
union all
 select accepter_id id from requestaccepted)
 select id , count(*) as num from base group by 1 order by num desc limit 1;