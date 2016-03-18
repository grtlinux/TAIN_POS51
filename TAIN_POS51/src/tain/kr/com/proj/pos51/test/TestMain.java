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
import java.io.FileReader;
import java.util.ResourceBundle;

import org.apache.log4j.Logger;

/**
 * Code Templates > Comments > Types
 *
 * <PRE>
 *   -. FileName   : TestMain.java
 *   -. Package    : tain.kr.com.proj.pos51.main
 *   -. Comment    :
 *   -. Author     : taincokr
 *   -. First Date : 2016. 3. 18. {time}
 * </PRE>
 *
 * @author taincokr
 *
 */
public class TestMain {

	private static boolean flag = true;

	private static final Logger log = Logger.getLogger(TestMain.class);

	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////

	private static void test01(String[] args) throws Exception {

		if (!flag) {
			/*
			 * ERROR
			 * TODO 2016.03.18 : How do I do in the future?
			 */
			String name = new Object(){}.getClass().getEnclosingClass().getName().replace('.', '/');
			if (flag) log.debug("name = " + name);
			
			File file = new File(name + ".sample");
			
			BufferedReader br = new BufferedReader(new FileReader(file));
			String line = null;
			
			while ((line = br.readLine()) != null) {
				System.out.println(line);
			}
			
			br.close();
		}
		
		if (flag) {
			String clsName = new Object(){}.getClass().getEnclosingClass().getName().replace('.', '/');
			ResourceBundle rb = ResourceBundle.getBundle(clsName);
			
			String path = rb.getString("TestMain.file.path");
			String name = rb.getString("TestMain.file.name");
			
			if (flag) log.debug(">" + path);
			if (flag) log.debug(">" + name);
			
			File file = new File(path + File.separator + name);
			BufferedReader br = new BufferedReader(new FileReader(file));
			String line = null;
			
			while ((line = br.readLine()) != null) {
				System.out.println("[" + line + "]");
			}
			
			br.close();
		}
	}
	
	
	public static void main(String[] args) throws Exception {
		
		if (flag) log.debug(">>>>> " + new Object(){}.getClass().getEnclosingClass().getName());
		
		if (flag) test01(args);
	}
}
