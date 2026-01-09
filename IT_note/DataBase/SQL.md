# SQL

## Ngôn ngữ định nghĩa dữ liệu (DDL)
```SQL
-- Tạo bảng --
CREATE TABLE <Tên table 1>, <Tên table 2> 

 -- Xóa bảng (Phải hủy khóa ngoại trước khi xóa bảng) --
DROP TABLE <tên table> 

-- Thêm cột vào bảng --
ALTER TABLE <Tên table> ADD <Tên cột> <Kiểu dữ liệu> 

-- Xóa cột khỏi bảng --
ALTER TABLE <Tên table> DROP COLUMN <Tên cột> 

-- Thay đổi cột của bảng (Thay datatype mới) --
ALTER TABLE <Tên table> ALTER COLUMN <Tên cột> <Kiểu dữ liệu mới> 

-- Thay đổi tên bảng và cột -- 
EXEC sp_rename <Tên table>, <Tên table mới>
EXEC sp_rename <Tên table.tên colum>, <Tên column mới>, <COLUMN>




```


## Ngôn ngữ thao tác dữ liệu (DML)
```SQL
-- Một vài toán tử
LIKE '2452%%%%'
IN ('Giá trị 1', 'Giá trị 2')

-- Thêm mới dữ liệu --
INSERT INTO <Tên bảng> VALUES ('Giá trị 1', 'Giá trị 2', 'Giá trị 3')

-- Xóa dữ liệu --
DELETE FROM <Tên bảng> WHERE <Điều kiện>

-- Sửa --
UPDATE <Tên bảng> SET <Tên cột 1> = <Giá trị mới>, <Tên cột 2> = <Giá trị mới> WHERE <Điều kiện>

-- Sao chép bảng dữ liệu --
SELECT *INTO <Tên bảng mới> FROM <Tên bảng cũ>
```

## Ngôn ngữ truy vấn dữ liệu
```SQL
    SELECT (DISTINCT) <Cột 1>, <Cột 2>  
    FROM <Tên bảng 1> JOIN <Tên bảng 2> on <Điều kiện>
    (WHERE <Điều kiện>)
    (GROUP BY <Danh sách thuộc tính gom nhóm>)
    (HAVING <Điều kiện nhóm>)
    (ORDER BY <Cột 1> ASC, <Cột 2> DESC)

    -- Phép toán tập hợp --
    INTERSECT
    UNION
    EXCEPT 
    
    -- Phép gom nhóm --
    
```




## Ràng buộc toàn vẹn
- Một số ràng buộc toàn vẹn hay gặp
![DATABASE_image/image copy 10.png](<DATABASE_image/image copy 10.png>)
- Một số cách tạo ràng buộc toàn vẹn
![alt text](<DATABASE_image/image copy 11.png>)
![alt text](<DATABASE_image/image copy 12.png>)
![alt text](<DATABASE_image/image copy 13.png>)



