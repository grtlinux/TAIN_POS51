/**
 * Copyright 2014, 2015, 2016 TAIN, Inc. all rights reserved.
 *
 * Licensed under the GNU GENERAL PUBLIC LICENSE, Version 3, 29 June 2007 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.gnu.org/licenses/
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * -----------------------------------------------------------------
 * Copyright 2014, 2015, 2016 TAIN, Inc.
 *
 */
package tain.kr.com.proj.pos51.test;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.nio.ByteBuffer;
import java.nio.charset.Charset;
import java.util.ResourceBundle;

import org.apache.log4j.Logger;

/**
 * Code Templates > Comments > Types
 *
 * <PRE>
 *   -. FileName   : FileTransferCharSetTestMain.java
 *   -. Package    : tain.kr.com.proj.pos51.test
 *   -. Comment    :
 *   -. Author     : taincokr
 *   -. First Date : 2016. 3. 18. {time}
 * </PRE>
 *
 * @author taincokr
 *
 */
public class FileTransferCharSetTestMain {

	private static boolean flag = true;

	private static final Logger log = Logger.getLogger(FileTransferCharSetTestMain.class);

	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////

	private static void test01(String[] args) throws Exception {
		
		ResourceBundle rb = null;
		
		if (flag) {
			String clsName = new Object(){}.getClass().getEnclosingClass().getName();
			
			rb = ResourceBundle.getBundle(clsName.replace('.', '/'));
		}
		
		if (flag) {
			BufferedReader br = new BufferedReader(new FileReader(new File(rb.getString("tain.test01.in.file.path") + File.separator + rb.getString("tain.test01.in.file.name"))));
			String line = null;
			
			while ((line = br.readLine()) != null) {
				System.out.println("01 [" + line + "]");
			}
			
			br.close();
		}
	}
	
	private static void test02(String[] args) throws Exception {
		
		ResourceBundle rb = null;
		
		if (flag) {
			String clsName = new Object(){}.getClass().getEnclosingClass().getName();
			
			rb = ResourceBundle.getBundle(clsName.replace('.', '/'));
		}
		
		if (flag) {
			BufferedReader br = new BufferedReader(new FileReader(new File(rb.getString("tain.test02.in.file.path") + File.separator + rb.getString("tain.test02.in.file.name"))));
			String line = null;
			
			while ((line = br.readLine()) != null) {
				System.out.println("02 [" + line + "]");
				
				Charset euckr = Charset.forName("EUC-KR");
				ByteBuffer byteBuffer = euckr.encode(line);
				byte[] retBytes = byteBuffer.array();
				
				System.out.println("02 [" + new String(retBytes) + "]");
			}
			
			br.close();
		}
	}
	
	private static void test03(String[] args) throws Exception {
		
		if (flag) {
			if (flag) System.out.println();
			
			String hello = "¾È³çÇÏ¼¼¿ä...¤¡¤¤¤§";
			if (flag) System.out.println("hello : " + hello);
			
			if (flag) System.out.println();
			
			byte[] euckrHello = hello.getBytes(Charset.forName("euc-kr"));
			if (flag) System.out.println("euc-kr - length : " + euckrHello.length);
			
			String decodeFromEuckr = new String(euckrHello, "euc-kr");
			if (flag) System.out.println("String from euc-kr : " + decodeFromEuckr);
			
			if (flag) System.out.println();
			
			byte[] utf8Hello = decodeFromEuckr.getBytes("utf-8");
			if (flag) System.out.println("utf-8 - length : " + utf8Hello.length);
			
			String decodeFromUtf8 = new String(utf8Hello, "utf-8");
			if (flag) System.out.println("String from utf-8 : " + decodeFromUtf8);
		}
	}
	
	private static void test04(String[] args) throws Exception {
		
		ResourceBundle rb = null;
		
		if (flag) {
			String clsName = new Object(){}.getClass().getEnclosingClass().getName();
			
			rb = ResourceBundle.getBundle(clsName.replace('.', '/'));
		}
		
		if (flag) {
			String path = rb.getString("tain.test02.in.file.path");
			String name = rb.getString("tain.test02.in.file.name");
			
			File file = new File(path + File.separator + name);
			
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(file), "UTF-8"));
			String line = null;
			
			while ((line = br.readLine()) != null) {
				System.out.println("02 [" + line + "]");
				
				Charset euckr = Charset.forName("EUC-KR");
				ByteBuffer byteBuffer = euckr.encode(line);
				byte[] retBytes = byteBuffer.array();
				
				System.out.println("02 [" + new String(retBytes) + "]");
			}
			
			br.close();
		}
	}
	
	public static void main(String[] args) throws Exception {
		
		if (flag) log.debug(">>>>> " + new Object(){}.getClass().getEnclosingClass().getName());
		
		if (flag) test01(args);
		if (flag) test02(args);
		if (flag) test03(args);
		if (flag) test04(args);
	}
}
