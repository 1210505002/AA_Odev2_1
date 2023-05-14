# Önerilen Kodun Zaman Karmaşıklığı

`generateRandomArray` fonksiyonundaki işlemler ve tekrar sayılarına bağlı olarak zaman karmaşıklığı şöyledir: int i = 0 1 işlem gerçekleşir ve 1 kez tekrar eder, 1*1 = 1 gelir. i < size 1 işlem gerçekleşir ve n+1 kez tekrar eder, 1*(n+1) = n+1 gelir. i++ işlem sayısı 1 tekrarı n olduğundan 1*n = n olur. Döngünün içindeki a[i] = rand() % (2 * MAX_W) - MAX_W; işlemi tek bir işlemdir ve döngü tekrarı kadar yani n kez çalışır. 1*n = n bulunur. T(n) = 1 + (n+1) + n + n = 3n +2 hesaplanır. Sonuç O(n) olur. <br>

`quickSort` fonksiyonunun zaman karmaşıklığı: işlemin toplam karmaşıklığı, rekürsif çağrıların sayısı ve her bir çağrının karmaşıklığı ile belirlenir. Her rekürsif çağrıda partition fonksiyonu çağrılır. Partition fonksiyonunun karmaşıklığı O(n) olur. Rekürsif çağrılar durduğunda, dizinin parçalara bölünmesi nlogn hesaplanır. Ve dizi tam olarak taranır ve bölünür. Her bir aşama için n adım yapılır. Sonucu O(nlogn)’dir. <br>

`avgPositiveNumbers` fonksiyonunun zaman karmaşıklığı: if-else ifadeleri ve return döndürme işlemi sabit zaman alır ve for döngüsü n kez çalışır. Bu fonksiyonun zaman karmaşıklığı O(n) hesaplanır. <br>

`floydWarshall` fonksiyonunun zaman karmaşıklığı: üstteki iç içe iki for döngüsünün çalışması n^2, altta iç içe üç for döngüsü vardır ve çalışması n^3 olur. Büyük olan alınır ve sonuç O(n^3)’tür. <br>

`printArray` fonksiyonunun zaman karmaşıklığı: for döngüsünün içindeki if ve print işlemleri sabit zaman alır, for döngüsü ise n kez çalışır. Hesaplanan O(n)’dir. <br>

`printGraph` fonksiyonunun zaman karmaşıklığı: iç içe iki for döngüsü n^2 kez çalışır ve içteki işlemler sabit zaman alır. Sonuç O(n^2) olur. <br>

`printShortestDistances` fonksiyonunun zaman karmaşıklığı: iç içe iki for döngüsünden dolayı O(n^2) olur. <br>

Toplam sonuç = O(n) + O(nlogn) + O(n) + O(n^3) + O(n) + O(n^2) + O(n^2) En yüksek olan değer alınır ve kodun çalışma zamanı **O(n^3)** elde edilir. 



