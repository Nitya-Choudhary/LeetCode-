 int findContentChildren(vector<int>& student, vector<int>& cookie){
   sort(student.begin(), student.end());
   sort(cookie.begin(), cookie.end());
   int studentindex=0, cookieindex=0;
   while(studentindex<student.size() && cookieindex<cookie){
     if(cookie[cookieindex]>=student[studentindex]){
       studentindex++;
     }
   }
   return cookieindex;
 }
