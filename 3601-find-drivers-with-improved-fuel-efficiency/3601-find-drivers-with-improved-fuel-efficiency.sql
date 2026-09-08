# Write your MySQL query statement below
with tem as(
    select d.driver_id as driver_id,d.driver_name as driver_name,avg(t.distance_km / t.fuel_consumed) as first_half_avg
    from drivers d inner join trips t on d.driver_id = t.driver_id
    where month(t.trip_date) in (1,2,3,4,5,6)
    group by driver_id
),
tem2 as(
    select d.driver_id as driver_id,d.driver_name as driver_name,avg(t.distance_km / t.fuel_consumed) as second_half_avg
    from drivers d inner join trips t on d.driver_id = t.driver_id
    where month(t.trip_date) in (7,8,9,10,11,12)
    group by driver_id
)
select t1.driver_id,t1.driver_name,round(t1.first_half_avg,2) as first_half_avg,round(t2.second_half_avg,2) as second_half_avg,round(second_half_avg-first_half_avg,2) as efficiency_improvement 
from tem t1 inner join tem2 t2 on t1.driver_id = t2.driver_id
where round(second_half_avg-first_half_avg,2) > 0.0
order by efficiency_improvement desc,t1.driver_name;