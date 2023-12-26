# Write your MySQL query statement below
select * from Cinema where description <>'boring' and mod(id,2)!=0 order by rating desc;