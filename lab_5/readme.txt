sudo insmod random_gen.ko # Добавление модуля
lsmod | grep random_gen # Проверка на наличие
sudo mknod /dev/random_gen c $(grep random_gen /proc/devices | awk '{print $1}') 0  # хз
cat /dev/random_gen # Исползование
sudo rmmod random_gen # Удаление
