# Разпиновка

| LED_PIN | CONTROL_PIN1 | CONTROL_PIN2|
|:-----:  |:-----:       |:-------------|
| 1       | 0            | 4 |

# Индикатор для монохроматора

Бегущая зеленая полоска длино n=3

| CONTROL_PIN1  | CONTROL_PIN2| Индикация     |
|:-----:         |:-----:      | :-------------|
| 0             | 0           | Вся лента горит зеленым |
| 1             | 0           | Послока длиной n бежит вниз|
| 0             | 1           | Послока длиной n бежит вверх|
| 1             | 1           | Вся лента горит красным| 
