Tgin = stack time - rai voằ at ifme 
- Thông lượng: số lượng tiến trihf được hoàn thành trong đơn vị thời gian (tối đa)

- Arrival: thời gian đến
- Burst: Thời gian chạy
# FCFS (không trưng dụng)
- Ai tới trước thì chạy trước
# SJF ( ko trưng dụng)
- Chạy hết P1 , trong quá trình đó có những tiền trình nào được nạp vào sẽ tiến hành so sánh cái nào có burst time nhỏ nhất
# SRTF (SJF trưng dụng)
- Chạy và khi tới arrival thì coi burst time của nhỏ nhất thì được chạy. Nếu burst time = nhau thì nhường cho thg cũ
# Round Robin
- Có quantumtime = q
- Cứ q giây sẽ kiểm tra xem có thg nào trong hàng chờ. Và hoạt động theo hàng chờ cứ q giây sẽ dừng và nhường cho tiến trình khác
# Giải thuật độ ưu tiên đọc quyền
- Chạy hết P1, trong quá trình đó có những tiến trình được nạp vào sẽ tiến hành so sánh cái nào có priority cao hơn
# Cách tính thời gian
- time hoàn thành = mốc tgian hoàn thành - Arrival time
=> Time hoàn thành trung bình= (tổng time hoàn thành) / n
- time đợi = time hoàn thành - burst time
- time đáp ứng = mốc tgian bắt đầu - Arrival time   