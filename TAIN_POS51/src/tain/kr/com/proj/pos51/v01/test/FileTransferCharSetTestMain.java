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
package tain.kr.com.proj.pos51.v01.test;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
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
			}
			
			br.close();
		}
	}
	
	public static void main(String[] args) throws Exception {
		
		if (flag) log.debug(">>>>> " + new Object(){}.getClass().getEnclosingClass().getName());
		
		if (flag) test01(args);
		if (flag) test02(args);
	}
}
