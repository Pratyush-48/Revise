# Write your MySQL query statement below
with tem as(
    select customer_id,
    count(order_id) as coun,
    avg(case when time(order_timestamp) between '11:00:00' and '14:00:00' then 1
             when time(order_timestamp) between '18:00:00' and '21:00:00' then 1
             else 0 end) as peak,
    AVG(order_rating) AS av,
    AVG(CASE WHEN order_rating IS NOT NULL THEN 1 ELSE 0 END) AS rat
    from restaurant_orders
    group by customer_id
)
select customer_id,coun as total_orders,round(peak*100,0) as peak_hour_percentage,round(av,2) as average_rating from
tem
where coun>=3 and round(peak*100,2)>=60.0 and av>=4.0 and rat>=0.5
order by average_rating desc,customer_id desc;