WITH tem AS (
    SELECT 
        s.store_id AS store_id,
        s.store_name AS store_name,
        s.location AS location,
        i.quantity AS quantity,
        i.price AS price,
        i.product_name AS product_name,
        ROW_NUMBER() OVER (PARTITION BY s.store_id ORDER BY i.price DESC, i.quantity DESC) AS rn
    FROM inventory i 
    INNER JOIN stores s ON i.store_id = s.store_id
),
tem2 AS (
    SELECT 
        s.store_id AS store_id,
        s.store_name AS store_name,
        s.location AS location,
        i.quantity AS quantity,
        i.price AS price,
        i.product_name AS product_name,
        ROW_NUMBER() OVER (PARTITION BY s.store_id ORDER BY i.price ASC, i.quantity DESC) AS rn
    FROM inventory i 
    INNER JOIN stores s ON i.store_id = s.store_id
),
tem3 AS (
    SELECT 
        i.store_id AS store_id 
    FROM inventory i 
    GROUP BY store_id
    HAVING COUNT(inventory_id) >= 3
),
tem4 AS (
    SELECT * FROM tem WHERE rn = 1
),
tem5 AS (
    SELECT * FROM tem2 WHERE rn = 1
)
SELECT 
    t1.store_id,
    t1.store_name,
    t1.location,
    t1.product_name AS most_exp_product, 
    t2.product_name AS cheapest_product,
    ROUND(t2.quantity / t1.quantity, 2) AS imbalance_ratio
FROM tem4 t1 
INNER JOIN tem5 t2 ON t1.store_id = t2.store_id 
WHERE t1.store_id IN (SELECT store_id FROM tem3) 
  AND t1.quantity < t2.quantity 
ORDER BY ROUND(t2.quantity / t1.quantity, 2) DESC, t1.store_name ASC;