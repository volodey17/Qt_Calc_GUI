# Qt_Calc_GUI

**Список задач:**

- [x] Реализовать сигнально-слотовые соединения;
- [x] Переписать способ вывода инф. Qlabel вместо QLCDNumber
- [x] Добавить клавиши новых математических операций в GUI;
- [ ] (6/10) - Добавить реализацию операций;
- [x] Перерисовать GUI с использованием языка стилей CSS;
- [ ] (!) - ОТМЕНА! Переписать для клавиш "мат.операций" - подключение сигналов к слоту на основе указателей
(а не через макрос Q_OBJECT !);

Исправить баги в логике:

- [ ] IN + IN = Res потом IN - модифицирует RES, как продолжение IN
- [x] Двойное нажатие Equal  - ошибка индикации
