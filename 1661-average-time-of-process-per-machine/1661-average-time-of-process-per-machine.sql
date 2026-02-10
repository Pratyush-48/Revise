# Write your MySQL query statement below
select m1.machine_id,
round(avg(m2.timestamp-m1.timestamp),3) as processing_time  from
Activity m1 inner join Activity m2
on m1.machine_id = m2.machine_id AND m1.process_id = m2.process_id
AND m1.activity_type = 'start' AND m2.activity_type = 'end'
group by machine_id;