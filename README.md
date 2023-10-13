# Özel `ft_printf` Fonksiyonu

Bu repository, özel bir `ft_printf` fonksiyonunu içerir. Bu fonksiyon, C programları içinde metin tabanlı çıktıları biçimlendirmek ve yazdırmak için kullanılır. Aşağıda, `ft_printf` fonksiyonunun ne yaptığını, nasıl kullanılacağını ve nasıl çalıştığını anlatacağız.

## Proje Açıklaması

`ft_printf` fonksiyonu, biçimlendirilmiş metinleri yazdırmak için kullanılır. Bu fonksiyon, biçim dizisi (format string) olarak adlandırılan bir girdiyi alır ve bu girdiye göre metni düzenler ve yazdırır. Özel biçim belirteçleri (format specifier) kullanarak, farklı türlerde verileri metin halinde yazdırabilirsiniz. Bu, özellikle metin tabanlı bir kullanıcı arabirimi oluştururken veya dosyalara veri yazarken kullanışlıdır.

## Kullanım

`ft_printf` fonksiyonunu kullanmak için aşağıdaki adımları takip edebilirsiniz:

1. `ft_printf` fonksiyonunu projenize dahil edin. Bu, `ft_printf.c` ve `ft_printf.h` dosyalarını kullanarak yapılabilir.

2. İstediğiniz metni biçimlendirmek için bir biçim dizisi (format string) oluşturun. Biçim dizisinde özel biçim belirteçleri kullanabilirsiniz. Örneğin: `%d` (ondalık sayı), `%s` (dizi), `%c` (karakter) vb.

3. `ft_printf` fonksiyonunu çağırarak biçim dizisini ve gerektiği verileri sağlayın. Örneğin:

```c
ft_printf("Merhaba, %s! Bugün %d. gün.", "Dünya", 42);

