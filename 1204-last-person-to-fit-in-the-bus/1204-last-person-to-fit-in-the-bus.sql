# Write your MySQL query statement below
SELECT person_name
FROM (
    SELECT 
        person_name, 
        SUM(weight) OVER(ORDER BY turn) AS rolling_weight
    FROM Queue
) AS bus_queue
WHERE rolling_weight <= 1000
ORDER BY rolling_weight DESC
LIMIT 1;