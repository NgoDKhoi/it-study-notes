# Ghi Chú Cơ Sở Dữ Liệu

## Sơ đồ mô hình quan hệ
- `Entity` là thực thể (vuông)
- `Attribute` là thuộc tính và có thể có nhiều thuộc tính (tròn)
  + `Primary key` là khóa chính (gạch chân)
  + `Foreign key` là khóa ngoại
- `Relationship`: là mối quan hệ và có thể có thuộc tính (thoi)
  + 0-1:
  + 1-1:
  + 1-N: "Mỗi...thuộc một...", "Mỗi...có nhiều..."
  + N-N: "Nhiều...nhiều"

- `Thực thể yếu` là một thực thể phụ thuộc vào một thực thể khác
- `Mối quan hệ yếu  ` là một mối quan hệ giữa thực thể yếu và thực thể

## Mô hình quan hệ
- Lưu ý: nếu mối liên kết có thuộc tính đó thì thêm thuộc tính đó vào luôn

### Kết hợp nhị phân
- Mối liên kết n-n sẽ tạo quan hệ có khóa chính lấy từ khóa chính của quan hệ tạo nên quan hệ n-n
- Mối liên kết 1-n thì quan hệ 1 sẽ có thêm khóa ngoại lấy từ khóa chính của quan hệ n
- Mối liên kết 1-1:
  + Nếu min bằng nhau thì 1 quan hệ sẽ có thêm khóa ngoại lấy từ khóa chính của quan hệ còn lại
  + Nếu min khác nhau thì quan hệ 1 sẽ có thêm khóa ngoại lấy từ khóa chính của quan hệ 

### Kết hợp n-phân
- Tạo quan hệ mới có cùng tên với mối liên 
- Khóa chính là tổ hợp khóa chính của các quan hệ tạo nên mối liên kết

### Kết hợp đệ quy
![alt text](<DATABASE_image/image copy 2.png>)
### Khác
- Thực thể yếu chuyển thành 1 quan hệ và có thêm khóa chính là khóa chính từ thực thể nó phụ thuộc
- Thuộc tính đa trị (2 tròn) chuyển thành 1 quan hệ có khóa chính là thuộc tính đa trị và thuộc tính khóa
![alt text](<DATABASE_image/image copy 3.png>)
- Thuộc tính đa hợp
![alt text](<DATABASE_image/image copy.png>)


## Đại số quan hệ
- Có năm phép toán cơ bản:  
![alt text](<DATABASE_image/image copy 4.png>)
  + Phép chọn:
  ![alt text](<DATABASE_image/image copy 6.png>)
  + Phép chiếu:
  ![alt text](<DATABASE_image/image copy 7.png>)
  + Phép gán:
  ![alt text](<DATABASE_image/image copy 8.png>)
  
- Các phép toán không cơ bản nhưng hữu ích:  
![alt text](<DATABASE_image/image copy 5.png>)

- Có 6 câu:
 + 2 dễ
 + 1 tập hợp
 + 1 kết ngoài 
 + 1 phép chia
 + 1 gom nhóm




## SQL
```
    ALTER TABLE CONGNHAN
    ADD CONSTRAINT CT_THO CHECK(BacTho IN('1','2','3','4','5','6','7'))

    UPDATE SANPHAM
    SET TinhTrangSP = 'Chưa kiểm định'
    WHERE MaPX = 'PX05' AND NgaySX = '20/10/2024'
```
DONHANG(<u>MADH</u>, NGAYBAN, TONGTIEN, DATHANHTOAN)
```
UPDATE DONHANG
SET TONGTIEN = TONGTIEN * 0.98
WHERE NGAYBAN >= '1/11/2023'
    
DELETE FROM DONHANG
WHERE DATHANHTOAN = 'TRUE'
```



![alt text](<DATABASE_image/image copy 9.png>)
- Lưu ý khi muốn xóa một bảng thì cần xóa khóa ngoại tham chiếu tới bảng đó trước
- Lưu ý nếu khi delete hay update phải có where nếu không sẽ hiểu là chọn tất cả





## Thực hành
![alt text](DATABASE_image/image.png)
