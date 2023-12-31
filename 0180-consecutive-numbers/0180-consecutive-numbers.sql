select distinct l1.num as ConsecutiveNums 
from logs as l1 inner join logs l2 
on l1.id=l2.id+1 
inner join logs as l3 
on l2.id=l3.id+1 
where 
l1.num=l2.num and
l2.num=l3.num;
