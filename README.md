# Kompilace a spuštění 
Kompilace a spuštění přímo na zařízení MicroZed je umožněno přiloženým Makefile souborem. Samotná kompilace je spuštěna klasickým `make`. Ke správnému fungování je nutnost nainstalovaného arm gcc cross compileru. Výsledný spustitelný soubor lze spustit příkazem:
```bash
  ./main
  ```
Kompilace přímo do zařízení pomocí ssh je vyvoláno voláním `make run`.

Tento makefile je přímo převzatý z [mzapo_template](https://gitlab.fel.cvut.cz/b35apo/mzapo_template).
## Nastavení Makefile
### Připojení přes SSH
Ke kompilaci na zařízení přes ssh je potřeba přepsat IP adresu MicroZed.
```Makefile
  TARGET_IP = 192.168.223.xxx
  ```
### Zdrojové soubory
V Makefile je nutné uvést všechny zdrojové soubory.
```Makefile
  SOURCES = main.c mzapo_phys.c mzapo_parlcd.c serialize_lock.c ball_logic.c knob_handler.c lcd_handler.c led_line.c move_objects.c objects_init.c redraw_objects.c menu.c
  SOURCES += font_prop14x16.c font_rom8x16.c
  ```
