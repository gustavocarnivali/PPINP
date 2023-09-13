if [ $1 = 1 ]; then
	#Init
	echo -Init
	mkdir output
	cd pipeline/
	#Diamond
	echo -Diamond
	cd Diamond/
	./diamond makedb --in ../../input/$5 -d reference
	./diamond blastp --query ../../input/$2 --db reference.dmnd --outfmt 6 qseqid sseqid qstart qend pident length slen evalue sstart send stitle qlen --evalue 1e-10 --query-cover 50 --subject-cover 40 --out s_1_string.out --threads $6
	./diamond blastp --query ../../input/$3 --db reference.dmnd --outfmt 6 qseqid sseqid qstart qend pident length slen evalue sstart send stitle qlen --evalue 1e-10 --query-cover 50 --subject-cover 40 --out s_2_string.out --threads $6
	rm reference.dmnd
	mv s_1_string.out ../
	mv s_2_string.out ../
	cd ..
	#Filter
	echo -Filter
	mv ../input/$4 FilterBD/
	cd FilterBD
	mkdir ../GraphGenerate/bds
	mv $4 connections.txt
	split -d -n$6 connections.txt scone
	for ((i=0; i<=$6-1; i++))
	do
	if [ $i -lt 10 ]; then
	echo scone0$i
	./exe scone0$i &
	fi
	done
	wait
	rm scone*
	mv connections.txt $4
	mv $4 ../../input/
	cd ..
	#Graph Generate
	echo Graph Generate
	mv s_1_string.out GraphGenerate/
	mv s_2_string.out GraphGenerate/
	cd GraphGenerate
	split -d -n$6 s_1_string.out sout
	for ((i=0; i<=$6-1; i++))
	do
	if [ $i -lt 10 ]; then
	echo sout0$i
	./exe sout0$i s_2_string.out >> output.txt &
	else
	./exe sout$i s_2_string.out >> output.txt &
	fi
	done
	wait
	rm sout*
	./exe s_1_string.out s_2_string.out > output.txt
	rm s_1_string.out
	rm s_2_string.out
	mv output.txt ../
	rm -r bds
	cd ..
	#Score
	echo Score
	sort output.txt | uniq > output2.txt
	rm output.txt
	mv output2.txt output.txt
	mv output.txt Score/
	cd Score
	./exe > output.s
	cd ..
	mv Score/output.s score.txt
	#ADD Subtitle
	echo ADD Subtitle
	cat ../input/$2 > ../input/3.fa
	cat ../input/$3 >> ../input/3.fa
	cut -d" " -f1 score.txt > output2.txt
	cut -d" " -f2 score.txt >> output2.txt 
	sort output2.txt | uniq > output3.txt
	mv score.txt ../output/
	rm output2.txt
	mv output3.txt output.txt
	mv ../input/3.fa Subtitle/
	mv output.txt Subtitle/
	cd Subtitle/
	./exe > output.fa 
	rm 3.fa
	rm output.txt
	mv output.fa ../
	cd ..
	#SignalP
	echo SignalP
	mv output.fa signalp/
	cd signalp/
	./exe.sh
	mv output.fa ../
	mv saidasignalp.txt outputsignalp.txt
	cd ..
	mv signalp/outputsignalp.txt ../output
	#TargetP
	echo TargetP
	mv output.fa targetp/test
	cd targetp/
	./exe.sh
	mv test/output.fa ../
	cd ..
	mv outputtargep* ../output
	#TMHMM
	echo TMHMM
	mv output.fa tmhmm
	cd tmhmm/
	./exe.sh
	mv output.fa graph.fa
	mv graph.fa ../../output
	cd ..
	mv saidatmhmm.txt outputtmhmm.txt
	mv outputtmhmm.txt ../output
	#End 	
fi
if [ $1 = 2 ]; then
	#Init
	echo -Init
	mkdir output
	cd pipeline/
	#Filter
	echo -Filter
	mv ../input/$4 FilterBD/
	cd FilterBD
	mkdir ../GraphGenerate/bds
	mv $4 connections.txt
	split -d -n$8 connections.txt scone
	for ((i=0; i<=$8-1; i++))
	do
	if [ $i -lt 10 ]; then
	echo scone0$i
	./exe scone0$i &
	fi
	done
	wait
	rm scone*
	mv connections.txt $4
	mv $4 ../../input/
	cd ..
	#Graph Generate
	echo Graph Generate
	mv ../input/$6 GraphGenerate/
	mv ../input/$7 GraphGenerate/
	cd GraphGenerate
	split -d -n$8 s_1_string.out sout
	for ((i=0; i<=$8-1; i++))
	do
	if [ $i -lt 10 ]; then
	echo sout0$i
	./exe sout0$i s_2_string.out >> output.txt &
	else
	./exe sout$i s_2_string.out >> output.txt &
	fi
	done
	wait
	rm sout*
	./exe $6 $7 > output.txt
	mv $6 ../../input/
	mv $7 ../../input/
	mv output.txt ../
	rm -r bds
	cd ..
	#Score
	echo Score
	sort output.txt | uniq > output2.txt
	rm output.txt
	mv output2.txt output.txt
	mv output.txt Score/
	cd Score
	./exe > output.s
	cd ..
	mv Score/output.s score.txt
	#ADD Subtitle
	echo ADD Subtitle
	cat ../input/$2 > ../input/3.fa
	cat ../input/$3 >> ../input/3.fa
	cut -d" " -f1 score.txt > output2.txt
	cut -d" " -f2 score.txt >> output2.txt 
	sort output2.txt | uniq > output3.txt
	mv score.txt ../output/
	rm output2.txt
	mv output3.txt output.txt
	mv ../input/3.fa Subtitle/
	mv output.txt Subtitle/
	cd Subtitle/
	./exe > output.fa 
	rm 3.fa
	rm output.txt
	mv output.fa ../
	cd ..
	#SignalP
	echo SignalP
	mv output.fa signalp/
	cd signalp/
	./exe.sh
	mv output.fa ../
	mv saidasignalp.txt outputsignalp.txt
	cd ..
	mv signalp/outputsignalp.txt ../output
	#TargetP
	echo TargetP
	mv output.fa targetp/test
	cd targetp/
	./exe.sh
	mv test/output.fa ../
	cd ..
	mv outputtargep* ../output
	#TMHMM
	echo TMHMM
	mv output.fa tmhmm
	cd tmhmm/
	./exe.sh
	mv output.fa graph.fa
	mv graph.fa ../../output
	cd ..
	mv saidatmhmm.txt outputtmhmm.txt
	mv outputtmhmm.txt ../output
	#End 	
fi
