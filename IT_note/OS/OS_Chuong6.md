# Chương 6
- Điều kiện cần để xảy ra deadlock:
  + `Mutual Exclusion` (Loại trừ tương hỗ): ít nhất 1 tài nguyên được giứ the nonsharable mode
  + `Hold and wait`: một tiến trình giữ một tài nguyên và dợi thêm tài nguyên khác do tiến trình khác giữ
  + `No preemption`: không trưng dụng tài nguyên
  + `Circular Wait` (chu trình đợi): tồn tại một tập các tiến trình đang đợi sao cho.....

## Đồ thị wait for
- Có 1 loại đỉnh: đỉnh tiến trình

## Đồ thị RAG
- Có 2 loại đỉnh: đỉnh tiến trình và đỉnh tài nguyên
- Có 2 loại cạnh: 

## Safe và Unsafe
- Ban đầu 12 filex`xx
- Còn 3 file mà P1 cần thêm 2. Sau khi thực hiện cho P1 thì availbe là 5
- Làm xong mà availbe bằng số file ban đầu thì đúng

## Giải thuật Banker
- Có 3 điều kiện:
- Có 4 loại ma trận:

- Bài tập hay gặp, (dù đề không yêu cầu cũng làm 2 này):
  + Tính ma trận Need
  + Tính số lượng thực thể tối đa của mỗi loại tài nguyên
  

  + work = availbe
  + 1 2 2 bé hơn 3 3 2
  + Làm xong đối chiếu với 10, 5 ,7 mà khác thì sai
  + Giải thuật trả về 1 chuỗi là Safe
  + Kết luận hệ thống ở trạng thái không an toàn

# Giải thuật yêu cầu tài nguyên cho tiến trình P1



