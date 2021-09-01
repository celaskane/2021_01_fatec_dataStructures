public class TesteArgsMac{
    public static void main(String[] args) { //args é um vetor de String
        int s=0;
        for (int i=0; i<args.length; i++) {
            //System.out.println(args[i]);
            s+= Integer.parseInt(args[i]);
        }
        System.out.println(s);
    }
}

/*public static void main(String args[]) { //args é um vetor de String

    int v[], x; //v é um vetor de inteiros e x é um inteiro comum

    int[] v1, v2; //v1 e v2 são vetores de inteiro
*/
