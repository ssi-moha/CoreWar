for s in files/*.s  ; do
../resources/asm $s 1>0
./asm $s
chmod 777 tes.cor
cat tes.cor > test1
(echo $s | sed s/..$/.cor/) | xargs cat  > test2
res=$(diff test1 test2)
if [ -z "$res" ]
then
	echo "\033[32mOK\033[0m" $s
else
	echo "\033[31mKO\n $res \033[0m" $s
fi
rm test1
rm test2
rm -rf tes.cor
(echo $s | sed s/..$/.cor/) | xargs rm
done
