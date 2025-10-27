Folien: [[04_Algorithmen_Teil_2_04.pdf|Algorithmen Teil 2 - 04]]

# Smart Pointer
Es gibt **Smart Pointer** und **Raw Pointer**. Mit Raw Pointern verwaltet man Heapspeicheradressen, die mit `new`- und `delete`-Expressions manuell zugewiesen und freigegeben werden müssen. Mit Smart Pointern wird der Speicher implizit freigegeben.

Es gibt mehrere Smart Pointer
- Shared Pointer
- Weak Pointer
- Unique Pointer
- Auto Pointer (seit C++17 obsolet).

## Shared Pointer
Mit Shared Pointern kann ein Objekt von mehreren Pointern verwaltet werden. Jedes Objekt weiß, durch wieviele Shared Pointer es verwaltet wird (*Reference Counting*). Falls der Reference Counter auf 0 geht, wird das Objekt vom Heap entfernt, indem der Destruktor aufgerufen und dann der Speicher freigegeben wird.

### Shared Pointer anlegen und verwenden

```cpp
std::shared_ptr<MeineKlasse> ptr; // Erzeugt einen Shared Pointer,
								  // der noch kein Objekt verwaltet
ptr = std::make_shared<MeineKlasse>( /*Konstruktorparameter*/ );
```

Mit `ptr` spricht man nun den Pointer selbst an, und mit `*ptr` das Objekt, das sich hinter dem Pointer verbirgt.

```cpp
std::shared_ptr<int> ptr = std::make_shared<int>(42);  
std::cout << *ptr << std::endl; // Druckt 42  
*ptr = 55;                      // Setzt das verwaltete Objekt auf 55  
std::cout << *ptr << std::endl; // Druckt 55
```

Member des verwalteten Objekts erreicht man mit `(*ptr).member`.
Syntactic sugar dafür ist `ptr->member`.

```cpp
class MeineKlasse {  
public:  
	// ...  
	int eine_member_fkt();  
	// ...  
};  

std::shared_ptr<MeineKlasse> ptr = std::make_shared<MeineKlasse>( /* Parameter */ );  
std::cout << (*ptr).eine_member_fkt() << std::endl; // Druckt eine Zahl  
std::cout << ptr->eine_member_fkt()   << std::endl; // Druckt eine Zahl
```

Wenn ein anderer Pointer auf dasselbe Objekt zeigen soll, macht man das einfach mit dem Zuweisungsoperator.

```cpp
std::shared_ptr<int> ptr = std::make_shared<int>(42);  
std::shared_ptr<int> anderer_ptr = ptr; // Beide verwalten dasselbe Objekt.  
*anderer_ptr = 55;                      // Setzt das verwaltete Objekt auf 55  
std::cout << *ptr << std::endl;         // Druckt 55
```

Wenn man wissen will, wieviele Pointer auf dasselbe Objekt zeigen, macht man das mit `ptr.use_count()`.

```cpp
std::shared_ptr<int> ptr = std::make_shared<int>(42);  
std::shared_ptr<int> anderer_ptr = ptr;    // Beide verwalten dasselbe Objekt.  
std::cout << ptr.use_count() << std::endl; // Druckt 2
```

Die Funktion `ptr.reset()` setzt den aktuellen Pointer zurück, ohne andere Pointer auf dasselbe Objekt zu verändern.

## Weak Pointer
### Motivation
Mit Shared Pointern kann es vorkommen (wenn man nicht aufpasst), dass Objekte im Heap zyklisch aufeinander zeigen, ohne dass vom Stack aus darauf zugegriffen werden kann. Dann hat man eine **zirkuläre Zeigerabhängigkeit**, und die entsprechenden Objekte werden nicht vom Heap entfernt, weil ja auf jedes Objekt noch ein Zeiger zeigt.
Mit Weak Pointern kann man dieses Verhalten vermeiden.

Weak Pointer *merken* sich die Adresse eines Objekts, aber mit ihnen kann man dieses Objekt *nicht verwalten*.
Objekte, auf die nur ein Weak Pointer zeigt, werden gelöscht.

### Beispiel
Beispiel doppelt verkettete Liste: wenn man ausschließlich Shared Pointer nimmt, und dann Head und Tail wegschmeißt, hat man eine zyklische Abhängigkeit:
![[Doppelt_verkettete_Liste.png]]
$$\downarrow$$
![[DVL_zyklische_Abhaengigkeit.png]]
In diesem Fall würde die Liste im Heapspeicher liegenbleiben, ohne dass man drankommt.

Aber wenn die Rückpfeile nur Weak Pointer sind:
![[DVL_weak_pointer.png]]
$$\downarrow$$
![[DVL_weak_pointer_geloescht.png]]
$\rightarrow$ Alles wird gelöscht.

### Verwendung
Um mit einem Weak Pointer ein Objekt zu verwalten, braucht man `weak_ptr.lock()`. Mit dieser Funktion wird aus einem Weak Pointer ein Shared Pointer.

```cpp
// Legt neuen Shared Pointer an  
std::shared_ptr<int> ptr = std::make_shared<int>(42);  
// Legt Weak Pointer an, der auf dasselbe Objekt zeigt  
std::weak_ptr<int> anderer_ptr = ptr;  
// Objekt wird von EINEM Pointer verwaltet  
std::cout << ptr.use_count() << std::endl;  
// Illegal! Weak Pointer erlaubt keinen direkten Zugriff!  
std::cout << *anderer_ptr << std::endl;  
// Zugriff ist nach Erzeugung des temporären Shared Pointer zulässig.  
// Das Objekt wird in diesem Moment von ZWEI Pointern verwaltet.  
std::cout << (anderer_ptr.lock()).use_count() << std::endl;  
// Der temporäre Shared Pointer verwaltet das Objekt nicht mehr.  
// Das Objekt wird also von EINEM Pointer verwaltet  
std::cout << ptr.use_count() << std::endl;
```

## Unique Pointer
Objekte, die durch *genau einen* Zeiger verwaltet werden sollen, referenziert man durch einen **Unique Pointer**.

```cpp
std::unique_ptr<MeineKlasse> u_ptr;
u_ptr = std::make_unique<MeineKlasse>( /* Parameter */ );
```

Man darf keinen Zugriff auf ein Objekt erhalten, indem man einen Unique Pointer kopiert:
```cpp
// Illegal!
auto x = u_ptr;
```

Man darf aber eine Referenz auf den Unique Pointer machen:
```cpp
// Erlaubt.
auto& x = u_ptr;
```

Wichtige Memberfunktionen von Unique Pointern:
- `reset`: entfernt das aktuell verwaltete Objekt vom Heap.
- `swap`: vertauscht die verwalteten Objekte zwischen zwei Unique Pointern

Der Unique Pointer kann als bool-Wert interpretiert werden. Dieser ist genau dann `true`, wenn der Unique Pointer ein Objekt auf dem Heap verwaltet.

# Raw Pointer
Raw-Pointer heißen auch **C-Pointer**. 

Verwendung:
```cpp
MeineKlasse* ptr; // Erzeugt einen Pointer, der auf MeineKlasse zeigen kann.
ptr = new MeinKlasse( /* Parameter */ );

(ptr*).eine_member_funktion(); // ruft eine Member-Funktion auf
ptr->eine_memeber_funktion();  // ruft die Member-Funktion genauso auf

delete ptr; // Löscht das Objekt im Heap (muss passieren, sonst wird nichts aufgeräumt)
```

