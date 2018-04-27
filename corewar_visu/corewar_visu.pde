import java.nio.file.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.*;
import java.io.*; 
BufferedReader  reader;
String          line;
String          linepc;
int             x;
int             y;
String          path;
int              test;
int              pause;

void setup()
{
  size(2000, 1200);
  background(0);
  x = 40;
  y = 40;
  pause = 0;
  path = "/Users/lfujimot/TC/OUTPUT.txt";
  textSize(40);
}
//http://couleurs.optimisation-web.com/rgb
void draw()
{
  x = 40;
  y = 40;
  test = 0;
  File f = new File(path);
  try{
    
    if (f.getAbsoluteFile().exists() && countLines(path) == 69 && pause == 0)
  {
    reader = createReader(path);
   try
    {
   
      line = reader.readLine();
      displayWinner(line);
      line = reader.readLine();
      if (line == null)
      {
        test = 1;
        cleanFile(f);  
    }
    else
    {
      parsePlayers(line);
      line = reader.readLine();
      if (line == null)
       {
         test = 1;
       cleanFile(f);  
     }
     else
     {
      parseVM(line);
      linepc = reader.readLine();
      if (linepc == null)
        {
          test = 1;
        cleanFile(f);  
      }}}
    }catch (IOException e) {
        e.printStackTrace();
        line = null;
      }
    line = "x";
    if (test == 0){
    while (line != null)
    {
      try {
        line = reader.readLine();
      } catch (IOException e) {
        e.printStackTrace();
        line = null;
      }
      if (line == null) {
        cleanFile(f);
        break ;
        // Stop reading because of an error or file is empty
        //noLoop();  
      } else {
        printLine(line, x, y);
      //  text(line, 40, y);
        y += 15;
      //String[] pieces = split(line, TAB);
      //int x = int(pieces[0]);
      //int y = int(pieces[1]);
      //point(x, y);
    }
    }}
    if (test == 0)
      parsePC(linepc);
  }}
  catch(Exception e){}
}

void  printLine(String line, int x, int y)
{
  for (int i = 0; i < line.length(); i++)
  {
    stroke(255);
    setColorAccordingToPlayer(line.charAt(i));
    rect(x, y, 15, 15);
    x += 17;  
  }
}

void  setColorAccordingToPlayer(char c)
{
  if (c == 'a')
    fill(74, 163, 223);
  else if (c == 'b')
    fill(64, 212, 126);
  else if (c == 'c')
    fill(242, 202, 39);
  else if (c == 'd')
    fill(231, 76, 60);
  else if (c == 'x')
    fill(44, 62, 80);
  else if (c == 'A')
    fill(41,128,185);
  else if (c == 'B')
    fill(166,107,190);
  else if (c == 'C')
    fill(166,107,190);
  else if (c == 'D')
    fill(166,107,190);
}

String readOnce()
{  
  return ("");
}

void  parsePlayers(String line)
{
  if (line != null){
 List<String> player_num = new ArrayList<String>();
 List<String> player_live = new ArrayList<String>();
 List<String> player_name = new ArrayList<String>();
 Matcher m = Pattern.compile("(?<=p:)[+-]?[0-9]+(?=;)").matcher(line); 
println(line);
 while (m.find()) {
   player_num.add(m.group());
 }
 Matcher n = Pattern.compile("(?<=nbl:)[+-]?[0-9]+(?=;)").matcher(line); 
 while (n.find()) {
   player_live.add(n.group());
 }
 Matcher o = Pattern.compile("(?<=nm:)[^;]+(?=;)").matcher(line); 
 while (o.find()) {
   println(o.group());
   player_name.add(o.group());
 }
 println("SIZE" + player_name.size());
 fill(44, 62, 80);
 rect(1175, 25, 700,1000);
 fill(255);
 int posY = 600; // rajouter un boolean pour le mettre que au debut la premiere fois
 for (int i = 0; i < player_num.size(); i++)
 {
   fill(255);
   text("Player(" + player_num.get(i) +"): " + player_name.get(i), 1200, posY, -30);
   textSize(30);
   text("lives in current period: " + player_live.get(i), 1200 + 50, posY + 60 - 20, -30);
   posY += 120;
   println(player_num.get(i));
   textSize(40);
 }}
}

 void  parseVM(String line)
{
  if (line != null){
 List<String> cycle = new ArrayList<String>();
 List<String> cycle_delta = new ArrayList<String>();
 List<String> cycle_to_die = new ArrayList<String>();
 List<String> nb_live = new ArrayList<String>();
 List<String> process = new ArrayList<String>();
 List<String> max_checks = new ArrayList<String>();
 
 Matcher m = Pattern.compile("(?<=c:)[+-]?[0-9]+(?=;)").matcher(line); 
 while (m.find()) {
   cycle.add(m.group());
 }
 Matcher mm = Pattern.compile("(?<=cd:)[+-]?[0-9]+(?=;)").matcher(line); 
 while (mm.find()) {
   cycle_delta.add(mm.group());
 }
 Matcher n = Pattern.compile("(?<=ctd:)[+-]?[0-9]+(?=;)").matcher(line); 
 while (n.find()) {
   cycle_to_die.add(n.group());
 }
  Matcher o = Pattern.compile("(?<=nbl:)[+-]?[0-9]+(?=;)").matcher(line); 
 while (o.find()) {
   nb_live.add(o.group());
 }
 Matcher p = Pattern.compile("(?<=pc:)[+-]?[0-9]+(?=;)").matcher(line); 
 while (p.find()) {
   process.add(p.group());
 }
 Matcher q = Pattern.compile("(?<=max:)[+-]?[0-9]+(?=;)").matcher(line); 
 while (q.find()) {
   max_checks.add(q.group());
 }
 //rect(1175, 25, 700,1000);
  fill(255);
  text("Cycle: " + cycle.get(0), 1200, 100, -30);
  text("CYCLE_TO_DIE: " + cycle_to_die.get(0), 1200, 160, -30);
  text("CYCLE_DELTA: " + cycle_delta.get(0), 1200, 220, -30);
  text("NBR_LIVE: " + nb_live.get(0), 1200, 280, -30);
  text("MAX_CHECKS: " + max_checks.get(0), 1200, 340, -30);
  text("Processes: " + process.get(0), 1200, 440, -30);
}}

void  parsePC(String line)
{
  int pcCounter;
  
  if (line != null){
 List<String> pc = new ArrayList<String>();
 
 Matcher m = Pattern.compile("(?<=pos:)[+-]?[0-9]+(?=;)").matcher(line); 
 while (m.find()) {
   pc.add(m.group());
 }
 //noFill();
 fill(255, 200 , 0);
 int posY = 600; // rajouter un boolean pour le mettre que au debut la premiere fois
 println ("size: "+ pc.size());
 for (int i = 0; i < pc.size(); i++)
 {
   pcCounter = Integer.parseInt(pc.get(i)) % 4096;
   println ("pc: " + i + "pc" + Integer.parseInt(pc.get(i)));
    rect(40 + (pcCounter % 64) * 17, 40 + (pcCounter / 64) * 15, 15, 15);   
 }
 fill(255);
}  
}

void  displayWinner(String line)
{
  fill(0);
  rect(0, 1050, 1880, 100);
 fill(255);
 textSize(60);
 text(line, 50, 1120, -30);
 textSize(40);
}


void  cleanFile(File f)
{
    try{
    PrintWriter writer = new PrintWriter(f);
    writer.print("");
    writer.close();
    }catch (Exception e){}
}

int countLines(String filename) throws IOException {
    InputStream is = new BufferedInputStream(new FileInputStream(filename));
    try {
        byte[] c = new byte[1024];
        int count = 0;
        int readChars = 0;
        boolean empty = true;
        while ((readChars = is.read(c)) != -1) {
            empty = false;
            for (int i = 0; i < readChars; ++i) {
                if (c[i] == '\n') {
                    ++count;
                }
            }
        }
        return (count == 0 && !empty) ? 1 : count;
    } finally {
        is.close();
    }
}

void keyPressed() {
  if (key == 'p') {
    
    if (pause == 1)
      pause = 0;
    else
      pause = 1;

  }
}
