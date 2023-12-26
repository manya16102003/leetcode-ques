# Write your MySQL query statement below
select name from Employee where id in(select managerID from Employee group by managerID having count(managerID)>=5);