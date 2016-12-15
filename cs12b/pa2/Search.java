//--------------------------------------------------------------------------------------------------------
// Search.java
// Aryan Samuel
// arsamuel
// CMPS 12B
// 04/12/16
// Programming Assignment 2
// Searches a file for specific targeted words. File and words are taken as cmd line arguments.
//--------------------------------------------------------------------------------------------------------

import java.io.*;
import java.util.Scanner;

class Search {
	
	public static void main (String[] args) throws IOException {
		
		Scanner in = null;
		String[] words;
		int LC=0, w;
		
		// Errors Statement
		if (args.length < 2) {
			System.out.println("Usage: Search file target1 [target2 ..]");
			System.exit(1);
		}
		
		// Open files
		in = new Scanner(new File(args[0]));
		
		// Line Counter
		while (in.hasNextLine()) {
			in.nextLine();
			LC++;
		}
		
		words = new String[LC];
		in = new Scanner(new File(args[0])); // Reset scanner to top of file
		
		while (in.hasNextLine()) {
			for (int i=0; i<LC; i++) {
				words[i] = in.nextLine();
			}
		}
			
		mergeSort(words, 0, LC-1);		
		
		for (int k=1; k<args.length; k++) {
			w = binarySearch(words, 0, LC-1, args[k]);
			if (w >= 0) {
				System.out.println(args[k] + " found");
			} else {
				System.out.println(args[k] + " not found");
			}
		}
			
		// Close files
		in.close();
		
	}
	
	// Merge Sort
	public static void mergeSort (String[] word, int p, int r) {
		int q;
		if (p < r) {
			q = (p+r)/2;
			mergeSort(word, p, q);
			mergeSort(word, q+1, r);
			merge(word, p, q, r);
		}
	}
	
	// Merge sorted strings
	public static void merge (String[] word, int p, int q, int r) {
		int n1 = q-p+1;
		int n2 = r-q;
		String[] w1 = new String[n1];
		String[] w2 = new String[n2];
		int i, j, k;
		
		for(i=0; i<n1; i++) w1[i] = word[p+i];
		for(j=0; j<n2; j++) w2[j] = word[q+j+1];
		i=0; j=0;
		
		for(k=p; k<=r; k++) {
			if (i<n1 && j<n2) {
				if (w1[i].compareTo(w2[j]) < 0) {
					word[k] = w1[i];
					i++;
				} else {
					word[k] = w2[j];
					j++;
				}
			} else if (i<n1) {
				word[k] = w1[i];
				i++;
			} else {
				word[k] = w2[j];
				j++;
			}
		}
	}
				
	// Binary Search Algorithm	
	public static int binarySearch (String[] word, int p, int r, String t) {
		int q;
		if (p > r) return -1;
		else {
			q = (p+r)/2;
			if (word[q].compareTo(t) == 0) {
				return q;
			} else if (word[q].compareTo(t) > 0) {
				return binarySearch(word, p, q-1, t);
			} else {
				return binarySearch(word, q+1, r, t);
			}
		}
	}

}
