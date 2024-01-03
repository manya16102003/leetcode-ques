with weightwithinrange as(
    select person_name , sum(weight) over(order by turn) as total_weight from queue
)
select person_name 
from weightwithinrange
where total_weight<=1000 order by total_weight desc limit 1;