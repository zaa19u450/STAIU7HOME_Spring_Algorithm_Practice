CC := gcc
INCPATH := ../inc/
OUTPATH := ./out/
SRCPATH := ./src/
UNIPATH := ./unit_tests/
SRCS := $(wildcard *.c)
INC := -I $(INCPATH)
CFLAGS := -std=c99 -Wall -Werror -Wextra -Wfloat-equal -pedantic -Wfloat-conversion -Wvla


#2 варианта сборки
.PHONY : debug 
debug : CFLAGS += -g3
debug : app.exe

.PHONY : release
release : CFLAGS += -DNDEBUG -g0
release : app.exe

# Общие объектные файлы
OBJS := $(OUTPATH)film.o $(OUTPATH)film_array.o $(OUTPATH)my_getdelim.o

# Объектные файлы, нужные только в модульном тестировании
OBJSUNIT := $(OUTPATH)check_film.o $(OUTPATH)check_film_array.o $(OUTPATH)check_my_getdelim.o
#$(OUTPATH)check_film_array.o

#сборка основной программы
app.exe : $(OBJS) $(OUTPATH)app.o
	$(CC) $^ -o $@
	
#сборка модульных тестов
unit_tests.exe : $(OBJS) $(OBJSUNIT) $(OUTPATH)check_main.o 
	$(CC) $^ -o $@ -lcheck

#компоновка тестирующих модулей
$(OUTPATH)check_%.o : $(UNIPATH)check_%.c
	cd out && $(CC) $(CFLAGS) $(INC) -c ../$<
	
#компоновка основных модулей
$(OUTPATH)%.o : $(SRCPATH)%.c
	cd out && $(CC) $(CFLAGS) $(INC) -c ../$<
	
# сборка и прогон модульных тестов	
.PHONY : unit 	
unit : unit_tests.exe
	./unit_tests.exe

# прогон функциональных тестов
.PHONY : func  	
func : app.exe
	cd func_tests && ./run_tests_09_01_01.bat
 
#зависиммости
%.d : %.c
	$(CC) -M $< > $@

include $(SRCS:.c=.d)

#очистка
.PHONY : clean 
clean :
	$(RM) $(OUTPATH)*.o *.exe *.d

# сборка и прогон модульных тестов с проверкой drmemory
#.PHONY : check_mem_unit 
#check_mem_unit : unit_tests.exe
#	drmemory -lib_blacklist "*" -batch -- ./unit_tests.exe
	
# прогон функциональных тестов с проверкой drmemory	
#.PHONY : check_mem_func 
#check_mem_func : app.exe
	# echo "negatives"
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\films.txt > func_tests\out.txt; true
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\films.txt year CasinoRoyale toomany > func_tests\out.txt; true
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\films.txt whatever > func_tests\out.txt; true
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\films.txt year two > func_tests\out.txt; true
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\films.txt year -2020 > func_tests\out.txt; true
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\films.txt year 100000 > func_tests\out.txt; true
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\no.txt year > func_tests\out.txt; true
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\neg_10_in.txt year > func_tests\out.txt; true
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\neg_13_in.txt year > func_tests\out.txt; true
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\neg_14_in.txt year > func_tests\out.txt; true
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\neg_15_in.txt year > func_tests\out.txt; true
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\neg_16_in.txt year > func_tests\out.txt; true
	# echo "positives"
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\pos_01_in.txt year > func_tests\out.txt
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\pos_02_in.txt title > func_tests\out.txt
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\pos_03_in.txt name > func_tests\out.txt
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\pos_04_in.txt year > func_tests\out.txt
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\pos_05_in.txt year > func_tests\out.txt
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\pos_06_in.txt year > func_tests\out.txt
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\pos_07_in.txt title Nobody > func_tests\out.txt
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\pos_08_in.txt name Nobody > func_tests\out.txt
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\pos_09_in.txt year 2000 > func_tests\out.txt
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\pos_10_in.txt year 2019 > func_tests\out.txt
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\pos_11_in.txt name Darabont > func_tests\out.txt
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\pos_12_in.txt title Avatar > func_tests\out.txt
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\pos_13_in.txt title "Shawshank Redemption" > func_tests\out.txt
	# drmemory -lib_blacklist "*" -batch -- ./app.exe func_tests\\pos_14_in.txt name hahn > func_tests\out.txt
	