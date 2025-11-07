# Chương 5: Đồng bộ tiến trình
## Race Condition
- `Race condition` là hiện tượng xảy ra khi các tiến trình cùng truy cập `đồng thời` vào `shared memory`. Và kết quả  cuối cùng sẽ phụ thuộc vào thứ tự thực thi của các tiến trình đang chạy đồng thời với nhau
- Hiện tượng race condition có thể dẫn đến việc dữ liệu bị sai và không nhất quán
- `Data consitent`: Tính nhất quán dữ liệu
- Để giải quyết thì cần đảm bảo sao cho tại `mỗi thời điểm `chỉ có `một tiến trình` được thao tác vào shared memory. Do đó cần cơ chế đồng bộ tiến trình
### Bài toán Producer vs Consumer
- 1 core CPU có thể có 2 tiến trình diễn ra đồng thời (thực thi đồng thời)
- `Bounded buffer` là một kỹ thuật lưu trữ dữ liệu hoạt động như hàng đợi, có kích thước cố định, thường được triển khai ở dạng mảng vòng. Giúp giải viết vấn đề Producer-Consumer.
  + Tránh Producer làm tràn bộ đệm (Overflow)
  + Tránh Cosumer lấy dữ liệu rỗng (Underflow) 
```
  Buffer_Size = n
  i= (i+1) % Buffer_Size
```
- Do quantum != 3 cycle nên mã máy của các lệnh thao tác bị thực thi xen kẽ và dẫn đến `Data inconsistency`

### Bài toán cấp phát PID
- Biến `next_available_pid` được kernel sử dụng để cấp phát PID cho tiến trình mới
- 2 tiến trình đồng thời tạo tiến trình con bằng hàm fork() => cùng lấy `next_available_pid` làm dịnh danh

## Vấn đề vùng tranh chấp
-  `Critical section` (vùng tranh chấp): là vùng code mà ở đó các tiến trình thực hiện tác động lên shared memory  
- `Remainder section`: thực hiện các thao tác thông thường, không đụng tới shared memory
- `Entry section`: Kiểm tra điều kiện trước khi vào vùng tranh chấp
- `Exit section`: Cài đặt các điều kiện sau khi rời vùng tranh chấp

### Yêu cầu dành cho lời giải
- (1) `Mutual exclusion` (loại trừ tương hỗ) : Khi P đang trong CS của nó thì không có Q nào khác đang thực thi trong CS của Q
- (2) `Progress` (tính tiến triển): Một tiến trình đang tạm dừng bên ngoài CS thì không được ngăn cản các tiến trình khác vào CS
- (3) `Bounded waiting` (chờ đợi giới hạn): Mỗi process chỉ phải chờ một khoảng thời gian có hạn định để được tiến vào CS. Không xảy ra tính trạng đói tài nguyên (Starvation)

#### Giải pháp phần mềm số 1        
- Thao tác `đơn nguyên` là thao tác không thể bị cắt ngang

## Mutex Locks
- Giải pháp này có tên gọi khác là `spinlock`
- Thao tác `accquire()` hoặc `release()` phải là thao tác `đơn nguyên`
- block() từ running sẽ thành waiting
- wakeup() từ running sẽ thành ready
####  Mutxex Locks không bị busy waiting
- Để tránh busy waiting thì tạm thời đặt tiến trình vào trạng thái ngủ
- Hệ điều hành cần cung cấp 2 thao tác:
  + `block`: tạm dừng và đặt tiến trình vào hàng đợi - `trạng thái ngủ` 
  + `wakeup`: xóa một tiến trình ra khỏi hàng đợi và đặt lại vào trong hàng đợi sẵn sàng - `đánh thức`
![alt text](<OS_image/image copy 4.png>)
#### Cách sử dụng mutex locks
- Thường khái báo toàn cục (để các tiểu trình có thể truy cập được vào mutex lock) và khởi tạo trong hàm main
- Cần xác định vùng tranh chấp trước khi thực hiện các thao tác trên khóa mutex

## Semaphore
- Busy waiting có ưu điểm là tiết kiệm tài nguyên CPU, nhược điểm là phải nhờ hệ điều hành
- Lý thuyết có thể - or +
- TH phải >= 0
```
    S1 
    signal (sem1)
    
    wait (sem1)
    S2
    signal (sem2)

    wait (sem2)
    S3
    signal (sem1)

    wait (sem1)
    S4
    signal (sem2)

    wait (sem2)
    S5
    signal (sem1)

    wait (sem1)
    S6
```

- Nếu dùng if, count=n thì producer không được thêm phần tử nhưng vẫn có chạy => lãng phí (busy waiting)
- Để ko lãng phí thì blocked => wait
- wait làm cho tài nguyên giảm đi / 
```
#P1 
wait(empty)
wait(mutex)
count++
signal(mutex)
signal(full)

#P2
wait(full)
wait(mutex)
count --
signal(mutex)
signal(empty)
```