# Write your MySQL query statement below
select e.name,b.bonus from Employee as e left join Bonus as b on e.empID=b.empID where b.bonus<1000 or bonus is null;