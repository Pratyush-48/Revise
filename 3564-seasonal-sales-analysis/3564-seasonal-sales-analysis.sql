# Write your MySQL query statement below
with tem as (
    select s.sale_id as sale_id,s.product_id as product_id,s.sale_date as sale_date,p.product_name as product_name,p.category as category,(s.price * s.quantity) as total_revenue,s.quantity as total_quantity,
    case 
        when month(sale_date)=01 then 'Winter'
        when month(sale_date)=02 then 'Winter'
        when month(sale_date)=12 then 'Winter'
        when month(sale_date)=03 then 'Spring'
        when month(sale_date)=04 then 'Spring'
        when month(sale_date)=05 then 'Spring'
        when month(sale_date)=06 then 'Summer'
        when month(sale_date)=07 then 'Summer'
        when month(sale_date)=08 then 'Summer'
        when month(sale_date)=09 then 'Fall'
        when month(sale_date)=10 then 'Fall'
        when month(sale_date)=11 then 'Fall'
    end as 'season'
    from sales s left join products p
    on s.product_id = p.product_id
),
tem2 AS (
    SELECT 
        season,
        category,
        SUM(total_quantity) AS total_quantity,
        SUM(total_revenue) AS total_revenue
    FROM tem
    GROUP BY season, category
),
tem3 as(
    select season,category,total_quantity,(total_revenue) as total_revenue,
    dense_rank() over (partition by season order by total_quantity desc,total_revenue desc,category asc) as rn
    from tem2
)
select season,category,total_quantity,total_revenue from tem3 where rn=1 order by season;